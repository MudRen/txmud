// snake_powder.c

inherit ITEM;

void create()
{
        set_name("蛇胆粉", ({"snake powder"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "小包");
                set("long", "这是一小包蛇胆磨成的粉末，可以卖给药店。\n");
                set("value", 250);
        }
        setup();
}
