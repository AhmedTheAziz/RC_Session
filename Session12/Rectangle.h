// 2-Class (test02.exe)
class Rectangle
{
private:
    float length;
    float width;

public:
    Rectangle::Rectangle() : length(0), width(0)
    {}
    void set_length(float l);
    float get_length();
    void set_width(float w);
    float get_width();
    float get_Area();
};
