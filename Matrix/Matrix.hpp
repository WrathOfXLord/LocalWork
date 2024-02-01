#pragma once

#include <initializer_list>
#include <ostream>
#include <array>
#include <iomanip>
#include <format>
#include <cassert>
#include <algorithm>

template <typename T, std::size_t M, std::size_t N>
class Matrix {
    friend std::ostream &operator<<(std::ostream &out, const Matrix<T, M, N> &mat) {
        out << std::right << std::setfill(' ');
        for(std::size_t x {}; x < mat.rowCount; ++x) {
            out << "|";
            for(std::size_t y {}; y < mat.columnCount; ++y) {
                out << std::setw(mat.ostreamWidth) << mat[x][y];
            }
            out << "|\n";
        }
        return out << std::left;
    }

private:
    const std::size_t rowCount;
    const std::size_t columnCount;
    int ostreamWidth;
    std::array<std::array<T, N>, M> data;

    template<std::size_t value>
    constexpr std::size_t assertSize() const { static_assert(value > 0 && value <= 255, "Size must be between 1 - 255!"); return value; }
    
    constexpr std::array<std::array<T, N>, M> makeArray(const std::initializer_list<std::initializer_list<T>> &values) noexcept {
        auto initListIterator {values.begin()};
        assert(M == values.size());
        std::array<std::array<T, N>, M> arr2D;
        
        for(auto &row: arr2D) {
            std::copy(initListIterator->begin(), initListIterator->end(), row.begin());
            assert(N == initListIterator->size());
            ++initListIterator;
        }
        return arr2D;
    }

    template <std::size_t index, typename Type, std::size_t rowCount, std::size_t columnCount>
    constexpr static void fillArray([[maybe_unused]]std::array<std::array<Type, columnCount>, rowCount>& result) {}


    template <std::size_t index, typename Type, std::size_t rowCount, std::size_t columnCount, typename Arg, typename ...Args>
    constexpr static void fillArray(std::array<std::array<Type, columnCount>, rowCount>& result, Arg&& arg, Args &&...args) {
        constexpr std::size_t outerIndex = index / N;
        constexpr std::size_t innerIndex = index % N;
        // std::cout << "index: " << index << ", outerIndex: " << outerIndex << ", innerIndex: " << innerIndex << "\n";
        result[outerIndex][innerIndex] = std::forward<Arg>(arg);
        fillArray<index + 1, Type, rowCount, columnCount>(result, std::forward<Args>(args)...);
    }

    template <typename Type, std::size_t rowCount, std::size_t columnCount, typename... Args>
    constexpr static std::array<std::array<Type, columnCount>, rowCount> makeNestedArray(Args &&...args) {
        static_assert(rowCount * columnCount == sizeof...(args), "Incorrect Row - Column Size or Missing Parameter Provided!");
        std::array<std::array<Type, columnCount>, rowCount> result {};
        constexpr std::size_t initialIndex {0};
        fillArray<initialIndex, Type, rowCount, columnCount>(result, std::forward<Args>(args)...);
        return result;
    }

public:
    void setOStreamWidth(int size) { ostreamWidth = size; }
    Matrix(): rowCount {assertSize<M>()}, columnCount {assertSize<N>()}, ostreamWidth {3} {}

    // faster without optimizations
    Matrix(const std::initializer_list<std::initializer_list<T>> &values) : rowCount {assertSize<M>()}, columnCount {assertSize<N>()}, ostreamWidth {3}, data {makeArray(values)} {}

    // faster with optimizations thanks to constexpr variables and templates
    template <typename ...Args>
    Matrix(Args &&...args) : rowCount {assertSize<M>()}, columnCount {assertSize<N>()}, ostreamWidth {3}, data {Matrix::makeNestedArray<T, M, N>(std::forward<Args>(args)...)} { }
    
    constexpr inline std::array<T, N> &operator[](size_t index) noexcept { return data[index]; }
    constexpr const inline std::array<T, N> &operator[](size_t index) const noexcept { return data[index]; }
    inline constexpr std::size_t getRowCount() const { return rowCount; }
    inline constexpr std::size_t getColumnCount() const { return columnCount; }
    
};

template <typename Type, std::size_t rowCount, std::size_t columnCount, typename... Args>
constexpr Matrix<Type, rowCount, columnCount> makeMatrix(Args &&...args) {
    return Matrix<Type, rowCount, columnCount> {std::forward<Args>(args)...};
}

template <typename Type, std::size_t rowCount, std::size_t columnCount>
constexpr Matrix<Type, rowCount, columnCount> makeMatrix(const std::initializer_list<std::initializer_list<Type>> &values) {
    return Matrix<Type, rowCount, columnCount> {values};
}
