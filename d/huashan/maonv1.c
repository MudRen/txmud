// Room: /d/huashan/maonv1.c

inherit ROOM;

void create()
{
	set("short", "ëŮ����");
	set("long", @LONG
����������ڲ�������̦�������е㻬����е�����ů��
���������ϵķ�����һ�����ڣ����������ﻺ������������
�㲻���е㻳�ɡ����깫����ס�����ĵط��𣿿�������Ҳ��
�����š�
LONG
	);
	
	set("exits", ([
		"southup" : __DIR__"maonv",
		"southdown":__DIR__"maonv2.c",
]));

	setup();
	replace_program(ROOM);
}
