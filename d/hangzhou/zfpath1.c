// Room: /d/hangzhou/zfpath1.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����ͨ��Ѳ������С·���������Կ������ݸ�������������
�����������Ű참����ʯ�̳ɵ�·�ϻ����Կ�������ɫ��Ѫ����
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"zfyuanzi",
  "east" : __DIR__"zfxunbu",
  "north" : __DIR__"zfpath2",
]));

	setup();
	replace_program(ROOM);
}
