//main.c ��֥��ͷ�˸�����
#include <room.h>
inherit ROOM;
int do_touch(string arg);
void create()
{
        set("short","����");
        set("long", @LONG
������ͷ�˸��Ĵ�����ӭ��ǽ����һ���ǳ����ձ��������
�񻭵��ǲ��ͷ������ʥ�޵Ĺ��¡����ߵ�ǽ���Ϲ����˱�����
����ȥɱ�����ڵģ���Ҳ����ͷ�˵���ݡ�����ǽ����һ��Сľ
�ţ�����ͨ�����á�
LONG
        );
        set("exits", ([
        "east":__DIR__"secrety",
        "west":__DIR__"garden",
        "south":__DIR__"courtyard",
]));
        set("item_desc",([
        "��":"���������ĸ��������������˼���ʥ�޵Ĺ��£����ȵ�һ���ƺ��ǲ��ͷ�ˡ�\n",
]));
        setup();
        create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,__DIR__"obj/jail_key");
}
void init()
{
        add_action("do_touch","touch");
}
int do_touch(string arg)
{
        object obj;
        object me;
        me=this_player();
        if (!arg||arg!="��")
        {
                tell_object(me,"���봥��ʲô��\n");
                return 0;
        }
        if (arg=="��")
        {
                obj=new(__DIR__"obj/jail_key");
                obj->move(me);
                tell_object(me,"��Ȼ��������ʲô�������Ͽ�͵͵�İ����������\n");
                message("vision",me->name()+"�ڻ���������ʲô������\n",environment(me),({me}));
                return 1;
        }
}
