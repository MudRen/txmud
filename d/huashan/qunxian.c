// Room: /d/huashan/qunxian.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ﱳ���嶥������������඼�����֡���᫵�ɽ·������
�����ɽ�ƶ��ޣ����ƻ���ɽ�䡣����ȥ�����������ġ��Ͼ�
�繵�����������ǻ�ɽ��Ϊ�վ��İٳ�Ͽ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"baichi",
  "southeast" : __DIR__"ligou",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
