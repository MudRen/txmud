#include <ansi.h>;

inherit ITEM;

void create()
{
        set_name(HIW"靖海十六路水寨兵符"NOR,({ "bing fu", "fu" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一个两寸长的令牌,上面刻着三个大字[靖海候]。\n");
                set("value", 10);
        }
}

