#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("红铜钥匙", ({"red copper key"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "\n这是一个红包上面刻着一行金字：\n\n                 " + HIY + "愿你新年快乐！\n\n                                                  "+HIC MUD_NAME + "巫师组上"+NOR+"\n\n里面还有像还有什么东西可以，你可以打开(open)它。\n");
                set("unit", "个");
        }
        setup();
}
