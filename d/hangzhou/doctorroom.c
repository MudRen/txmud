// Room: /d/hangzhou/doctorroom.c

inherit ROOM;

void create()
{
	set("short", "���м�");
	set("long", @LONG
����Ѧ���еļң�Ѧ����Ҳ�Ǻ��ݸ�������ҽ�����ر����
Ѧ�����β���������ҩ��ȫƾһ���ߴ����룬�����������ˣ���
����ȥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yongningn1",
]));

	set("objects",([
	__DIR__"npc/doctor" : 1,
]));

	setup();
	replace_program(ROOM);
}
