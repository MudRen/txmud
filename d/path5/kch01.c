// Room: /d/path5/kch01.c

inherit ROOM;

void create()
{
	set("short", "���С·");
	set("long", @LONG
����һ���ߵͲ�ƽ��������Ţ�����С·��ʮ�ֲ����ߡ���
���ò�һ����һ��ǳ�����У����в�ͣ�ı�Թ�ţ������Ҫ����
��ƫƧ����ɽ��ˮ�ĵط������������ƺ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch02",
  "north" : __DIR__"nanping",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
