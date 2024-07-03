/*
Ahmed Abdelaziz
Robotics Corner
Session25:
SOLID Principles
*/

#include <iostream>
// 1- S: Single Responsibilty (test01.exe)
#include <ostream> // 1
#include <string>  //1&2
#include <vector>  //1&2
#include <fstream> //1
#include <memory>  //2
// SRP is about : the class has one reason to change.
struct Journal //: public iJournal.
{
    /// <summary>
    /// the private or public members of c++
    ///
    ///</summary>
    std::string m_title;
    std::vector<std::string> m_entries;
    explicit Journal(const std::string &title) : m_title(title)
    {
        // m_title = title;
    }
    void add(const std::string &entry)
    {
        m_entries.push_back(entry);
    }

    /// <summary>
    /// not single responsbility
    ///
    ///</summary>
    /// param name="filename">the file name to saveentries </param>
    // void save(const std::string& filename)
    // {
    //     std::ofstream ofs(filename);
    //     for (auto& s: m_entries)
    //     {
    //         ofs<<s.c_str()<<std::endl;
    //     }
    // }
};
///< summary>
/// fix the class for single Res.
///</summary>
struct PrintEntriesManager
{
    ///< summary>
    /// static function for call the save OP
    ///</summary>
    ///< param name="j"></param>
    ///< param name="filename"></param>
    static void save(const Journal &j, const std::string &filename)
    {
        std::ofstream ofs(filename);
        for (auto &s : j.m_entries)
        {
            ofs << s << std::endl;
        }
    }

    /// creat Json file must download JSON library to include before using.
    /*    static void save(const Journal &j, const std::string &filename)
    {
        std::ofstream ofs(filename);
        //create a JSON object to store journal entries
        json entriesJson;

        for (const auto & entry : j.m_entries)
        {
           entriesJson.push_back(entry);
        }
        //write JSON object to file
        ofs<<entriesJson.dump(4); // pretty print with 4 spaces
        ofs.close(); //Don't forget to close the file stream!!
    }
    */
};
/*
int main(int argc, char **argv)
{
    Journal Alahram{"Alahram}"};
    Alahram.add("There was a visit from the Prime Minster of Egypt to India.");
    PrintEntriesManager::save(Alahram, "Al-Ahram.txt");
    return 0;
}
*/
/*
struct iJournal
{
    std::string m_title;
    std::vector<std::string> m_entries;
    virtual void add(const std::string& entry)=0;
};
*/

// 2- O: Open/Closed (test02.exe)
/// OCP
///< summary>
/// Classification of product by color, size, color & size in different classes
///</summary>
std::string vcolor[] = {"Red", "Green", "Blue"};
enum class Color
{
    Red,
    Green,
    Blue
};
std::string vsize[] = {"Small", "Medium", "Large"};
enum class Size
{
    Small,
    Medium,
    Large
};

struct Product
{
    std::string m_name;
    Color m_color;
    Size m_size;
};

typedef std::vector<Product *> Items;
/// <summary>
/// doesn't follow SOLID Principle.
/// </summary>
struct Products
{
    static Items by_color(Items items, Color color)
    {
        Items results;
        for (auto &i : items)
        {
            if (i->m_color == color)
            {
                results.push_back(i);
            }
        }
        return results;
    }

    static Items by_size(Items items, Size size)
    {
        Items results;
        for (auto &i : items)
        {
            if (i->m_size == size)
            {
                results.push_back(i);
            }
        }
        return results;
    }
    ///< summary>
    /// New req. to find prod. by colors & size.
    ///</summary>
    ///< param name="items"> the Products List</param>
    ///< param name="color"> Color Specs. </param>
    ///< param name="size"> Size Specs. </param>
    ///< returns> The Items that fit with the Specs. </return>

    static Items by_color_and_size(Items items, Color color, Size size)
    {
        Items results;
        for (auto &i : items)
        {
            if (i->m_color == color && i->m_size == size)
            {
                results.push_back(i);
            }
        }
        return results;
    }
};

/*The Fix using Specification Pattern*/
///< summary>
/// Interface for Specification.
///</summary>
///< typeparam name="T"></tyepparam>
template <typename T>
struct ISpecification
{
    virtual bool is_specification(T *item) = 0;
};
struct ColorSpec : public ISpecification<Product>
{
    Color _color;
    explicit ColorSpec(Color color)
        : _color(color)
    {
    }
    bool is_specification(Product *s) override
    {
        return (s->m_color == _color);
    }
};
struct SizeSpec : public ISpecification<Product>
{
    Size size;
    explicit SizeSpec(Size size)
        : size(size)
    {
    }
    bool is_specification(Product *s) override
    {
        return (s->m_size == size);
    }
};
/// <summary>
/// First Type Specification
/// </summary>
struct SizeAndColorSpecs : public ISpecification<Product>
{
    SizeSpec size;
    ColorSpec color;
    SizeAndColorSpecs(SizeSpec &size, ColorSpec &color)
        : size(size), color(color)
    {
    }
    bool is_specification(Product *s) override
    {
        return (size.is_specification(s) && color.is_specification(s));
    }
};
/*
struct AndSpecs : public ISpecification<Product>
{
    ISpecification& spec1;
    ISpecification& spec2;
    AndSpecs(ISpecification &spec1, ISpecification &spec2)
        : spec1(spec1), spec2(spec2)
    {
    }
    bool is_specification (Product *s) override
    {
        return (spec1.is_specification(s) && spec2.is_specification(s));
    }
};
*/

template <typename T>
struct IFind
{
    virtual std::vector<T *> Find(std::vector<T *> items, ISpecification<T> &spec) = 0;
};
struct FindProduct : public IFind<Product>
{
    virtual std::vector<Product *> Find(std::vector<Product *> items, ISpecification<Product> &spec)
    {
        Items results;
        for (auto &p : items)
        {
            if (spec.is_specification(p))
            {
                results.push_back(p);
            }
        }
        return results;
    }
};
///< summary>
///
///</summary>
///< param name= "argc"</param>
///< param name= "argv"</param>
///< returns></returns>
/*
int main(int argc, char**argv)
{
    Product Apple{"Apple",Color::Green,Size::Small};
    Product Car{"Car",Color::Blue,Size::Large};
    Product Tree{"Tree",Color::Green,Size::Large};

    ColorSpec green{Color::Green};
    SizeSpec large{Size::Large};
    SizeAndColorSpecs size_color{large,green};
    // AndSpec size_color{large,green};
    FindProduct fp;
    std::vector<Product*> allproducts{&Apple,&Tree,&Car};
     //auto results=fp.Find(allproducts,green);
     auto results=fp.Find(allproducts,size_color);
     for (auto&i:results)
     {
        std::cout<<i->m_name<<" : is "<<vcolor[(int)i->m_color].c_str()<<std::endl;
     }
     return 0;
}
*/
// 3- L: Liskov Subistitution Principle.()
/*
struct Shape
{
    // public:
    int m_Width;
    int m_Height;
        Shape(int width, int height)
        : m_Width(width), m_Height(height)
    {
    }
    virtual int width() const = 0;
    virtual void set_width(int m_Width) = 0;
    virtual int height() const = 0;
    virtual void set_height(int m_Height) = 0;
    virtual int Area() const = 0;
};

///< summary>
/// Liskov Substitution Principle the Parent Class must be Replaced out  substitutable with thier subtypes
///  the rule of IS-A the child object IS-A parent object such as (Triangle IS A Shape).
///</summary>

struct Rectangle  :public Shape
{
    int m_Width;
    int m_Height;
    Rectangle(int width, int height)
        : Shape(width,height)
    {}
    int width() const
    {
        return m_Width;
    }
    virtual void set_width(int m_width)
    {
        this->m_Width = m_width;
    }
    int height() const
    {
        return m_Height;
    }
    virtual void set_height(int m_height)
    {
        m_Height = m_height;
    }
    int Area() const
    {
        return m_Width * m_Height;
    }
};

struct Square : public Shape //:public Rectangle
{
    Square(int width, int height)
    : Shape(width,height)
    {
    }
    int width() const
       {
        return m_Width;
    }
    virtual void set_width(int m_width)
    {
        this->m_Width = m_width;
    }
    int height() const
    {
        return m_Height;
    }
    virtual void set_height(int m_height)
    {
        m_Height = m_height;
    }
    int Area() const
    {
        return m_Width * m_Height;
    }
    };
    ///<End_of_Implementation>
    /// Lecture didn't provide more info. had to stop but the idea has been understood.
    ///</End_of_Implementation>
    int main()
    {
        return 0;
    }
  */

// 4-I: Interface Segregation Principle.()

