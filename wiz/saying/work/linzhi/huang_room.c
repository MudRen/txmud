//huang_room.c Ǯׯ�ص����ڡ�
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","Ǯׯ����");
        set("long", @LONG
��������֥��Ǯׯ�µ����ң�ǽ���ϵ�ţ�ʹ����յ�����ʮ
�������������������˸о��˵���ɭ�ֲ������������������ɱ
��̫���ˡ�ǰ��ǽ�������еġ�ͭ��桻�������ۡ�
LONG
        );
        set("exits", ([
        "east":__DIR__"bank_d/exit",
]));
        set("item_desc",([
        "ͭ���":"���ı����ˢ�����ƺ��������˴����������ҡҡ��yao������"
]));
        set("objects",([
        __DIR__"npc/real_huang":1
]));
        setup();
}
void init()
{
        add_action("do_yao","yao");
}
int do_yao(string arg)
{
        object me=this_player();
        if (!arg||arg!="ͭ���")
        {
                tell_object(CYN"��Ҫҡʲô��\n"NOR,me);
                return 0;
        }
        else 
        {
                say("$Nҡ��ҡǽ���ϵĻ�棬�������Աߴ򿪵İ���",me);
                me->move(__DIR__"lz_wroad2");
        }
}
