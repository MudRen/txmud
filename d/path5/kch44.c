// Room: /d/path5/kch44.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
�������ɽ�µ�һƬ�ݵأ��ݶ�����ʮ��ïʢ���м仹����
��һ���Ұ����һ������ǧ��ľ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch45",
  "north" : __DIR__"kch43",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
