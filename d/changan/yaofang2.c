// Room: /d/changan/yaofang2.c

inherit ROOM;

void create()
{
	set("short", "��ҩ��");
	set("long", @LONG
�����Ǿ�����ҩ����ҩ�ĵط���һ�ź��صĹ�̨�Ѳ�֪����
���ˣ���̨�Ǽ��Ŵ���ҩ��һ�����ֵ��ƹ������������ϴ�
ҩ���������С������ȡҩ��Ũ�ص�ҩ�����㲻̫��������Ǹ�
���뿪����ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yaofang",
]));
	set("no_clean_up", 0);

	set("objects",([
	__DIR__"npc/doctor_li" : 1,
]));
	setup();
	replace_program(ROOM);
}
