#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("��ͭԿ��", ({"red copper key"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "\n����һ������������һ�н��֣�\n\n                 " + HIY + "Ը��������֣�\n\n                                                  "+HIC MUD_NAME + "��ʦ����"+NOR+"\n\n���滹������ʲô�������ԣ�����Դ�(open)����\n");
                set("unit", "��");
        }
        setup();
}
