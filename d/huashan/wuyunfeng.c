// Room: /d/huashan/wuyunfeng.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǲ����¡���̧ͷ������ֻ��һ����ɫ��ɽ��������
һ���������Կ��У��Ǿ��ǲ����롣ɽ����������֮�ϣ�·��
��һ�ף��������±������ͣ���������ס�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"xiaolu9",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
