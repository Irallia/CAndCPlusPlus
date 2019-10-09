                                    // C-style enums:
enum class Color                    // enum Color
{                                   // {
    red, blue, green, yellow, noColor //      red, blue, green, yellow, noColor
};  //; is important!               // };

Color opponent(Color const c)
{
    //ToDo: break statement unnötig???
    switch (c)
    {
    case Color::red:
        return Color::green;
    case Color::green:
        return Color::red;
    case Color::blue:
        return Color::yellow;
    case Color::yellow:
        return Color::blue;
    default:
        return Color::noColor;      // oder nutze std::optional um NULL einzuführen
    }
}

int main() {                                // C-style enum:
    // scoped ↓                             // unscoped ↓
    [[maybe_unused]] Color c = Color::blue; // Color c = blue;
    // not implicitly convertible:          // implicitly convertible:
    //int i = c;                            int i = c; // == 1
    // no arithmetic operators:             // arithmetic operators:
    //Color cc = red + blue;                Color cc = red + blue; // == green
}