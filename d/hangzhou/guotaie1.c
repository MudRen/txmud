// Room: /d/hangzhou/guotaie1.c

inherit ROOM;

void create()
{
	set("short", "��̩·");
	set("long", @LONG
�����Ǻ����������һ���֣����ݸ���֪�����ž���������
�����ϣ��������·�ϵ�����Ҳ�Ƚ��٣����⣬������ϱ���
��Զ�ھ�Ҳ�������������ϡ�
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"fishshop",
  "west" : __DIR__"cross1",
  "east" : __DIR__"guotaie2",
]));

	setup();
	replace_program(ROOM);
}
