// Room: /d/changan/eroad3.c

inherit ROOM;

void create()
{
	set("short", "���½�");
	set("long", @LONG
�����ǳ����ǵĶ���֣������볤���ǵĶ��Ų�Զ��������
Ҳ�����Ķ�����������һЩС������ͣ��ߺ���ţ���������ƺ�
���������š����������ͻ����������������⸽����������Ҳ��
��һЩ������������⡣�����Ǿ��������ӻ���-�������С�
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"eroad2",
  "west" : __DIR__"shanghang",
  "north" : __DIR__"eroad4",
]));

	setup();
	replace_program(ROOM);
}
