// Room: /d/hangzhou/zfpath3.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��С·����һֱͨ��һ���ɻ�����С·�Ķ�����Ǹ�
�õ������ˣ�С·�������Ǹ��õ�Χǽ����һ����һ�������Ļ�
԰��
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"zfhetang",
  "east" : __DIR__"zfyuanzi",
  "north" : __DIR__"zfgarden",
]));

	setup();
	replace_program(ROOM);
}
