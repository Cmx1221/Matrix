class Seq {
public:
    Seq(int n = 0);
    Seq(const Seq& other);
    ~Seq();

    void input();
    void set(int index, int value);

    int longestNonDec() const;
    int diffCount(const Seq& other) const;

    static int getCount();

private:
    int n;
    int* data;
    static int total;
};
