// Room: /d/path2/ch_k11.c

inherit ROOM;

void create()
{
	set("short", "��Ͽ��");
	set("long", @LONG
���������Ͽ�ڣ�λ�����λƺ��Ա��������Զ�����������
ԭͨ�����ϵıؾ�֮·��·��ʱ�й��������ˡ���·�߼���һ��
��ľ����(pai)��
LONG
	);
        set("item_desc",([
          "pai":"
	north   ������->����
	south   �봨��->�ɿ�->����
	west    ����
	east    �ڷ�ɽ
\n",
          "����":"
	north   ������->����
	south   �봨��->�ɿ�->����
	west    ����
	east    �ڷ�ɽ
\n",
])); 

	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ch_k10",
  "south" : __DIR__"ch_k15",
  "east" : __DIR__"shanlu1",
  "west" : __DIR__"ch_k12",
]));
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
