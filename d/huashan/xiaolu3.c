// Room: /d/huashan/xiaolu3.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
һЩ̦��ֲ��������С·��������С·�ϣ����ò�����ʮ��
���񡣷�һ����������ɳɳ�����죬���д���Ϫˮ������������
���ͷ��ȥ��ȴ�Ҳ���ˮ�ںδ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"juling_zu",
  "southdown" : __DIR__"xiaozi_feng",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
