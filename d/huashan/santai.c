// Room: /d/huashan/santai.c

inherit ROOM;

void create()
{
	set("short", "��Ϣ̨");
	set("long", @LONG
��ɽ�Ͼ�����һƽ̨���޹��˳ơ����޷�����շ塱������
�������פ��СϢƾ��Զ����������������۵������ɾ�������
�����κ����˶�����ȴ�������¡�����ԶԶ���ǻ�ɽ�ɵ���ϼ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"shanlu2",
  "southdown" : __DIR__"lvzu",
]));

	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
