// Room: /d/path1/ft_s4.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ɽ��С·��·�������ǴԴԵ��������롣��������
ϡ�٣�̧����ȥ����ͺͺ��ɽ��͸��һ˿˿���⣬�㲻�ɵüӿ�
�˽Ų���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ft_s3",
  "east" : __DIR__"ft_s5",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
