// shulin1.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
���ǳ������ߵ�һƬ���֣����о����ĵģ������Ի���һ�����������
����������ﾭ����Ұ�޳�û������������䣬ң��ͺ�,��Ϊ��ž���
���������˼������ء�
LONG
);
	set("outdoors", "houjizhen");

	set("exits", ([
            "east" : "/d/changan/out_changan_n",
	    "west" : __DIR__"shulin2",
          ]));

	setup();
	replace_program(ROOM);
}   