// Room: /d/path5/kch02.c

inherit ROOM;

void create()
{
	set("short", "���С·");
	set("long", @LONG
����һ���ߵͲ�ƽ��������Ţ�����С·��ʮ�ֲ����ߡ���
���ò�һ����һ��ǳ�����У����в�ͣ�ı�Թ�ţ������Ҫ����
��ƫƧ����ɽ��ˮ�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch03",
  "north" : __DIR__"kch01",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
