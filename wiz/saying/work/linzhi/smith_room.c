//smith_room.c ��֥���������
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
����������������ﶣ�������������ˣ��߽���������Ǳ�
���ݵ�������õ����˼�����ֻ��һλ���δ����ڻ���������
����ʲô�������������ֻ�ǻ�ͷ����һ�ۣ����������к��㡣
LONG
);
        set("exits", ([
        "north":__DIR__"lz_eroad3",
]));
        set("objects",([
        __DIR__"npc/smith" :1,
]));
        setup();
        replace_program(ROOM);
}
