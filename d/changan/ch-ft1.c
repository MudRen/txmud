// Room: /d/changan/ch-ft1.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������·���ɳ���ͨ������ٵ����������ž�ʦ�뱱������
���죬���Ը��ⷱ����·�����������������ӵġ����̵ġ�����
�󳵵�������ﲻ����·�߻���һЩС�̷��ڽ������ǳ����֡�
��ʱ�������������߷ɳ۶���������һ·���������ϲ�Զ����
�����ǵı����ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"out_changan_n",
  "north" : "/d/path1/cc_tch1",
]));
	set("outdoors", "chan-ft");

	setup();
	replace_program(ROOM);
}
