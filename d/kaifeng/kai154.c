// Room: /u/w/wangs/b/kai154.c

inherit ROOM;

void create()
{
	set("short", "ƫ��");
	set("long", @LONG
ƫ�����õ��ż򵥣��������ţ�ǽ�Ϲ��в��������Ķ��ǹ�
͢���ɫ�����ޡ����ҷ���������̨֦�ʣ�ǽ�����м��Ŵ�ľ
������������һ�Ŵ�ĺ�ľ���������滹���ź�ɫ�ĳ񲼡�����
����һЩ�飬����Щ�ķ��ı���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai150",
]));
        set("objects",([
        __DIR__"npc/lb": 1,
]));

	setup();
	replace_program(ROOM);
}
