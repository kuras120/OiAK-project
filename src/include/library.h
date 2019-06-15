#ifndef FLOATINGPOINT_LIBRARY_H
#define FLOATINGPOINT_LIBRARY_H

#include <string>
#include <vector>

class FloatingPoint {
private:
    std::vector<uint32_t> exponent_;
    std::vector<uint32_t> mantissa_;
public:
    /**
    * Standard constructors
    */
    explicit FloatingPoint(const std::vector<int32_t>& exponent, const std::vector<int32_t>& mantissa);
    /**
     * Getters
     */
    std::vector<uint32_t> getExponent(bool reversed=false);
    std::vector<uint32_t> getMantissa(bool reversed=false);
    /** Returns the sign of the floating-point value -
    *  true stands for positive.
    */
    bool getExponentSign() const;
    bool getSign() const;
    /**
     * Standard operators
     */
    friend FloatingPoint operator+(const FloatingPoint &x, const FloatingPoint &y);
    friend FloatingPoint operator-(const FloatingPoint &x, const FloatingPoint &y);
    friend FloatingPoint operator*(const FloatingPoint &x, const FloatingPoint &y);
    friend FloatingPoint operator/(const FloatingPoint &x, const FloatingPoint &y);

    /**
     * Comparison operators
	 */
    bool operator==(const FloatingPoint& x);
    bool operator!=(const FloatingPoint& x);

    /**
     * Relational comparison operators
	 */
    bool operator<(const FloatingPoint &x);
    bool operator>(const FloatingPoint& x);
    bool operator<=(const FloatingPoint& x);
    bool operator>=(const FloatingPoint& x);

    /**
     * Combined assignment operators
	 */
    inline FloatingPoint operator+=(FloatingPoint& y);
    inline FloatingPoint operator-=(const FloatingPoint& y);
    inline FloatingPoint operator/=(const FloatingPoint& y);
    inline FloatingPoint operator*=(const FloatingPoint& y);
    /**
     *  Print
     */
    friend std::ostream& operator<<(std::ostream& os, FloatingPoint const & floatingPoint);

    static std::vector<FloatingPoint> compatibility(FloatingPoint x, FloatingPoint y, bool mantissaFlag=false);
    static std::vector<uint32_t> negate(std::vector<uint32_t> toNegate);
    static std::vector<uint32_t> alignExponents(FloatingPoint &x, FloatingPoint &y);
    static std::vector<uint32_t> shiftRight(std::vector<uint32_t> &vec, const std::vector<uint32_t> &rest);
    static void shiftLeft(std::vector<uint32_t> &vec, const std::vector<uint32_t> &rest);
};

#endif