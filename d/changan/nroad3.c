// /d/changan/nroad3  �����

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǳ����ǵı���֣����ڿ������ţ��������������˿�
ʼ������������ʱ���ܿ��������ڳ�������һЩѲ��������Ѳ�ߡ�
�����ǳ�����ݣ������ӵܶ�������ѧһЩ�书ǿ���壬Ҳ��
��һЩ�书����ѧ���ڴ˳��뽭����
LONG
        );

	set("exits", ([
		"north"		  : __DIR__"wuguan",
                "west"            : __DIR__"nroad4",
                "east"            : __DIR__"nroad2", ]) );

	set("outdoors","changan");

	set("objects",([
	NPC_DIR"xunpu" : 2,
]));
        setup();
	replace_program(ROOM);
}
