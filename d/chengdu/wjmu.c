// Room: /wiz/louth/c/wjmu.c

inherit ROOM;

void create()
{
	set("short", "����Ĺ");
	set("long", @LONG
�������Ĺ��Ϊ���ʱǰ��ʵ��������޵���Ĺ������Ĺ��
�ܴ󣬷ǳ���ΰ׳�ۡ�����ʵ�������ȥ�Ժ�������ĵ�Ĺ��
�����δ󷢺�ƣ���������û�����ܵ���Ĺ���еĲƱ�������
���붫�߾��ǽ���·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jguanlu4",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
