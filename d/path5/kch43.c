// Room: /d/path5/kch43.c

inherit ROOM;

void create()
{
	set("short", "ɽ�²ݵ�");
	set("long", @LONG
�������ɽ�µ�һƬ�ݵأ��ݶ�����ʮ��ïʢ���м仹����
��һ���Ұ����һ������ǧ��ľ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch44",
  "east" : __DIR__"kch42",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
