// Room: /d/huashan/yuntai.c

inherit ROOM;

void create()
{
	set("short", "��̨��");
	set("long", @LONG
����ɽ�ƹ��ʣ�����ȫ�Ǿ��ڣ�ֻ��һ��ɽ��ͨ�������ɽ
�塣���Ʒǳ���Ҫ�����Ϸ嶥���������У���ƮƮ����֮�С���
���������ɾ���������������乬������һ�ȵĻ�ɽ�۽�������
����С�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"husunchou",
]));
        set("outdoors", "huashan");
        set("objects", ([__DIR__"npc/bird":2 ]));
	setup();
}
