//real_jail.c �η����
inherit ROOM;
void create()
{
        set("short","�η�");
        set("long", @LONG
������һ��СС���η���ǽ���Ϲ��ŵ��ˮ�飬�ǳ��ĳ�
ʪ�������ֱ������ס�ĵط��������˭��������������ǵ�
ù֮���ˡ�
LONG
        );
        set("exits", ([
        "west":__DIR__"jail/exit",
]));
        setup();
}
