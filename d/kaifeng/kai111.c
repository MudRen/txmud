// Room: /d/kaifeng/kai111.c

inherit ROOM;

void create()
{
	set("short", "���ҩ��");
	set("long", @LONG
���ҩ�̲����ڿ�����������кܶ���صĲ����Ƕ��ϵ���
��ץҩ��������Ϊҩ�̵�����Ҳ��һλ��ҽ�����������Ѿ�û��
������֪���ˣ���Ҷ������С���Ҫ�����������ⲻ��˵��ϲ��
ɱ�ˣ�����˵ֻҪ�㻹û�����������ܴ���������������Ҫ��
�����ɴ˿ɼ�����ҽ��֮������
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chenlaoban" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kai106",
  "north" : __DIR__"yaofang2",
]));

	setup();
	replace_program(ROOM);
}
