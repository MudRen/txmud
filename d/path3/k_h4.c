// Room: /d/path3/k_h4.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����·���ӿ����ݵ�ʮ�����ߣ��㲻�ò�ʮ�ֵ�ע��
�Ž��£��㲻�þ�Ҫ����һ�ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_h3",
  "east" : __DIR__"k_h5",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
