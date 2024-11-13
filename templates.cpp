template<typename T, typename U>
class PointsCounter {
public:
    PointsCounter& operator=(const PointsCounter& rhs)
    { this.t = rhs.t; return *this; }
    T get_t() { return t; };
    void set_t(T t_) { t = t_; };
    void set_counter(const std::function<T(U)>& _c)
    { counter = _c; }
    template <typename Container>
    void add_points( Container c )
    {
        t += std::transform_reduce(c.begin(), c.end(),
            0, std::plus{}, counter
        );
    }
private:
    T t;
    std::function<T(U)> counter;
};
