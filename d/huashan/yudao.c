// Room: /d/huashan/yudao.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ߵ����ֻ���������ƣ�ɽ�¸��ʡ�����������㲻��
����һ�Σ��·�Ҫ���㴵�������Ŀһ����������������ף�
��������һ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"mingya",
  "southdown" : __DIR__"xiaolu9",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
