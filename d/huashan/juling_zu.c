// Room: /d/huashan/juling_zu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���͵�ɽ������Լ�Գ�һ���޴����ӡ��������������ľ�
�����ˡ���������뻪ɽ�������Ѿ���Զ�ˡ���ʱ�а��ƴ���
ͷ��Ư�����㲻������Ϣһ�£������ȳԵ�ȵ�ɡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xiaolu4",
  "southdown" : __DIR__"xiaolu3",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
