// /d/hangzhou/rl3.c

inherit ROOM;

void create()
{
        set("short", "������ջ��¥");
        set("long", @LONG
��¥�ǿ�ջ�ĸ߼��ͷ��������϶����ź�ɫ��ձ�ӣ�¥����
��վ��С������ʱ�Ⱥ���˵Ĳ���������ϸ�ģ�������غ�
�ǿɹۣ�������һЩ���̾޼ֳ����������ס��
LONG
        );
        set("exits", ([ 
            "down"  : __DIR__"rl2",
]));

	set("sleep_room", 1);
	set(SAFE_ENV,1);
	set("hotel",1);
        setup();
        replace_program(ROOM);
}

