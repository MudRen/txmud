// Room: /d/hangzhou/guotaie2.c

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
  "west" : __DIR__"guotaie1",
  "east" : __DIR__"guotaie3",
  "north" : __DIR__"shutaishop",
]));

	setup();
	replace_program(ROOM);
}
