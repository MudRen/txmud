inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG"����"NOR, ({ "zhu xiao" , "xiao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������\n");
                set("value", 100000);
        }
}
void init()
{
        add_action("do_chui","chui");
}
int do_chui(string arg)
{
        object me;
        me = this_player();
        if (arg != "xiao" && arg != "��")
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->query_temp("marks/louth_chui"))
                return notify_fail("�����ڴ������ء�\n");
                message_vision(MAG"$N������������˶��˵����ɡ�\n\n"NOR,me);
                me->set_temp("marks/louth_chui",1);
                call_out("qu", 8, me);
                me->start_busy(4);
                return 1;
}
int qu()
{
        object me=this_player();
        message_vision(MAG"$Nһ�����꣬��������һ�㡣\n"NOR,me);
        me->delete_temp("marks/louth_chui");
        return 1;
}

