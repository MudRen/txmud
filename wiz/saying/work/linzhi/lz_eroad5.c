//lz_eroad5.c ��֥�嶫�ڸ�ɭ�������ӵĵط�
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","�嶫ɽ·");
        set("long", @LONG
�߳�ԭʼɭ�֣�һ��С·�������ζ�ȥ���ƺ�ͨ��һ��С��
ׯ���������������������ԭ���ϱ���һƬ���֣���Ҷ��𣬷�
�����ˣ�����΢���ƺ���ˮ�����������ߵ�����һ��é�ݣ���ϡ
�����е㺺���Ӱ�ӡ�·����һ�����ӡ�
LONG
        );

        set("item_desc",([
        "����":HIR"ע�⣡ǰ��ɭ����·��ͨ�����л���ʥ�����ˣ�\n"NOR,
]));
        set("exits", ([
        "east":__DIR__"maowu",
        "west":__DIR__"lz_eroad4",
        "north":__DIR__"forestend",
]));
        setup();
}
void init()
{
        add_action("do_pass","pass");
}
int do_pass(string arg)
{
        object me;
       me=this_player();
        if (!arg)
        return notify_fail("��Ҫ��Խ���\n");
        if (arg=="������"||arg=="maple") {
        if (this_player()->query_temp("mark/������")) {
        write("��һͷ���������.......\n");
        message("vision",me->name()+"һͷ��������֣�ת�ۼ�Ͳ�����.......\n",environment(me),({me}));
        me->move(__DIR__"maple_s");
        message("vision",me->name()+"���˹�����\n",environment(me),({me}));
         return 1;
}
        else return notify_fail("�㿴�˰��죬�������Ŷ��롣\n");
        }
}
