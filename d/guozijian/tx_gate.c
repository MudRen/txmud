// Room: /d/guozijian/tx_gate.c 

inherit ROOM;

void create() 
{ 
	set("short", "̫ѧ��");
	set("long", @LONG
�����ǹ��Ӽ�ĵڶ����ţ���һ�����ţ�ǽ�嶼�ǻ���ר��
��Ѫ��ɫ���ŵ��Ϸ������׽���д�ߡ�̫ѧ�š����Ա߿��о���
��ͼ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"yongdao2",
		"south" : __DIR__"yongdao1",
]));
	setup();
	replace_program(ROOM);
}
