// Room: chengxf5.c�׻���

inherit ROOM;

void create()
{
        set("short", "�׻���");
	set("long", @LONG
�����ǳ���ة�ฮ�ľ�������һ���������ȿ��Կ�������һ
����ң�����׻����ĸ����֣�����򰾢��������ľ���֣�һ��
��֪��д����ֵ�������ٳ�����������͸��һ�ְ���������
վ���絶��������ɱ�����ڡ�����������ֱͨǰԺ�����ȡ�
LONG
	);

        set("exits", ([
  "east" : __DIR__"chengxf4",
]));
        set("item_desc", ([ /* sizeof() == 2 */
                "�׻���": "�׻��� �������֣��Ծ�������\n",
]));

	set("objects",([
	__DIR__"npc/shiye" : 1,
]));

        setup();
	replace_program(ROOM);
}