// Room: /d/shaolin/beilin3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������µı��֣��ߵ������Ѿ�����һЩ�б���ԫ�ˣ�
������˵�����±����ز��ã���Ϊ����ľ�Զ����ɳ�Ĵ�ʴ����
����ʯ�����а��ˡ������������в��ٹ۹���ھ۾����������
��ʯ���ϵ��֡������������������֣����Ǵ����á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"beilin2",
  "west" : __DIR__"ciyuntang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
