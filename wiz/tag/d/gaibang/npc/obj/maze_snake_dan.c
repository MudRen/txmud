// maze_snake_dan.c

inherit ITEM;

void create()
{
        set_name("���ߵ�", ({"mang_snake dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ߵ���\n");
                set("value", 100);
        }
        setup();
        call_out("become_rotten", 720);
}

void become_rotten()
{
        object me = this_object();
        object where = environment(me);
        object dan = new(__DIR__"rotten_dan");
        dan->move(where);
        if(environment())
                tell_object(environment(),"���ߵ��õ��ˣ�������������ζ��\n");
        destruct (me);
}
