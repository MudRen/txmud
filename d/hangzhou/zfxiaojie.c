// Room: /d/hangzhou/zfxiaojie.c

inherit ROOM;

void create()
{
	set("short", "С��뷿");
	set("long", @LONG
������֪������Ů���Ĺ뷿����������һ��̴ľԲ��������
����һյ�͵ƺͼ����飬��ǽ�ĵط���С����㴲��ȷʵ��ʵ�
�������Ա���һ��СС����ױ̨���������俴��ȥʮ�ֵ����¡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zfroom",
]));

	setup();
	replace_program(ROOM);
}
