// Room: /d/path2/ch_t22.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·��·������ϡ��س���һЩֲ�������
����������˾������Ե�ʮ�ֻ������ɴ��򱱾��ǰ����ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ch_t21",
  "southwest" : __DIR__"ch_t23",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
