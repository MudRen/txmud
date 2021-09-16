// /std/room/duchang.c
// by Find.

#define BASE_KAR 20 // ��׼��Ե
#define BASE_QUOTIETY 10 // ��׼ʤ��
#define MAX_QUOTIETY 50 // ���ʤ��
#define MIN_QUOTIETY 5 // ���ʤ��
#define KAR_IMPROVE 1 // ��Եÿ���ڻ�׼��Ե1���ڻ�׼ʤ���������ӵ�ʤ�ʵ���
#define SKILL_IMPROVE 2 // ÿ����10 �������ڻ�׼ʤ���������ӵ�ʤ�ʵ���

inherit ROOM;

private void do_result();

private string *dianshu = ({
"
	�� 

",
"	��

	    ��
",
"	��
	  �� 
	    ��
",
"	��  ��

	��  ��
",
"	��  ��
	  ��
	��  ��
",
"	�� ��
	�� ��
	�� ��
",
});

private int betting,money,win,*points = allocate(3);
private object better;

// �Ƿ���Ӯ?
private int can_win(object me,string kind)
{
	int kar, quotiety, skill;

	kar = me->query_kar();

	if(kar = BASE_KAR)
		quotiety = BASE_QUOTIETY;

	if(kar < BASE_KAR)
		quotiety = BASE_QUOTIETY-(BASE_KAR-kar)*KAR_IMPROVE;

	if(kar > BASE_KAR)
		quotiety = BASE_QUOTIETY+(kar-BASE_KAR)*KAR_IMPROVE;

	skill = me->query_skill("betting",1);

	if(skill && skill >= 10)
		quotiety += skill/10*SKILL_IMPROVE;

	if(quotiety < MIN_QUOTIETY)
		quotiety = MIN_QUOTIETY;

	if(quotiety > MAX_QUOTIETY)
		quotiety = MAX_QUOTIETY;

	switch (kind)
	{
		case "all":
			if(random(100) > quotiety/5 )
				return 0;
			else
				return 2;
			break;
		default :
			if(random(100) > quotiety)
				return 0;
			else
				return 1;
	}
}

// ��������
private void bring_point(int n)
{
	int a,b,c;

	switch (n)
	{
		case -2:	// ������ͬ�ĵ�
			do
			{
				a = random(6)+1;
				b = random(6)+1;
				c = random(6)+1;
			}
			while( (a==b) && (b==c) );
			break;

		case -1:	// ����С��
			while(a<1||a>6||b<1||b>6||c<1||c>6)
			{
				a = random(6)+1;
				if((9-a) > 6 )
					b = random(6)+1;
				else
					b = random(9-a)+1;
				c = random(10-a-b)+1;
			}
			break;

		case 1:		// �������
			while(a<1||a>6||b<1||b>6||c<1||c>6)
			{
				a = random(6)+1;
				if((10-a-6) > 0)
					b = random(6-(11-a-6)+1)+(11-a-6);
				else
					b = random(6)+1;
				if((11-a-b) == 6)
					c = 6;
				else if((10-a-b) <= 0)
					c = random(6)+1;
				else
					c = random(6-(11-a-b)+1)+(11-a-b);
			}
			break;

		default:	// ��ͬ
			a = random(6)+1;
			b = a;
			c = a;
	}

	points[0] = a;
	points[1] = b;
	points[2] = c;
}

void init()
{
	add_action("do_bet","bet");
}

int do_bet(string arg)
{
	object mtype,me;
	string kind;

	if( betting )
		return notify_fail("�����ϲ����ˣ����°Ѱɡ�\n");
	if (!arg)
		return notify_fail("bet big|small|all  <������>\n");

	if(sscanf(arg,"%s %d",kind,money) != 2)
		return notify_fail("bet big|small|all  <������>\n");

	me = this_player();

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(!(mtype = present("silver_money", me)) || !is_money(mtype))
		return notify_fail("������û�����ӡ�\n");

	if((int)mtype->query_amount() < money)
		return notify_fail("������û����ô�����ӡ�\n");

	if(kind != "big" && kind != "small" && kind != "all")
		return notify_fail("��Ҫ�Ĵ󡢶�С���Ƕ�ȫɫ��\n");

	if(money < 1)
		return notify_fail("��Ҫѹ������������ע��\n");

	betting = 1;
	better = me;
	// �Ȱ����Ѻ�����Ӽ������������������һ�뷢�������ܳ�ȥ��Ӯ������Ǯ�������
	mtype->add_amount(-money);
	me->start_busy(3);

	win = can_win(me,kind);

	switch(kind)
	{
		case "big" :
			message_vision("$N�������ó�"+chinese_number(money)+"������ѹ�ڡ����ϡ�\n",me);
			bring_point(win?1:-1);
			break;
		case "small":
			message_vision("$N�������ó�"+chinese_number(money)+"������ѹ�ڡ�С���ϡ�\n",me);
			bring_point(win?-1:1);
			break;
		default :
			message_vision("$N�������ó�"+chinese_number(money)+"������ѹ�ڡ�ȫɫ���ϡ�\n",me);
			bring_point(win?0:-2);
	}

	call_out("show_point",2,0);
	return 1;
}

private void show_point(int n)
{
	string *view = ({
({
"\nһ�����������ﵯ�˼��£�ͣ�ڣ�\n\n",
"\nһ�����ӣ��������������˼��£����ͣ���ˣ�\n\n",
"\n���������໥һײ��һ��ֱ����ף�\n\n", }),

({
"\n��һ������ͣ��������\n\n",
"\n�ڶ��������������ת��ͣ��������˸���\n\n",
"\n���������໥һײ������һ������һ��ͣ�ڣ�\n\n", }),

({
"\n���һ�����������ﻬ�����£�����ͣ�ڣ�\n\n",
"\n�������һ�����������޵�ת����ͣ��������ͣ�ڣ�\n\n",
"\n���һ������Ҳ����ͣ���ˣ�\n\n", }),
});

	remove_call_out("show_point");

	if(n > 2)
	{
		do_result();
		return;
	}

	tell_room( this_object(),sprintf("%s%s",view[n][random(3)],
dianshu[points[n]-1]) );

	call_out("show_point",1,++n);
}

private void do_result()
{
	string output;
	object silver;
	int imp;

	betting = 0;

	output = sprintf("��%s��%s��%s��",chinese_number(points[0]),
		chinese_number(points[1]),chinese_number(points[2]) );

	if(points[0] == points[1] && points[1] == points[2])
		output += "���ӣ���\n";

	else if( (points[0]+points[1]+points[2]) < 11 )
		output += "С��\n";
	else
		output += "��\n";

	if(!better)
	{
		tell_room( this_object(),output);
		return;
	}

	if(!win)
	{
		output += sprintf("%s���� %d �����ӡ�\n",better->name(),money);
		tell_room( this_object(),output);
		return;
	}

	output += sprintf("%sӮ�� %d �����ӣ���\n",better->name(),win==1?money:money*8);

	if(environment(better) != this_object())
	{
		output += "�������ڳ���ӯ����ĳ����С�\n";
		tell_room( this_object(),output);
		return;
	}

	tell_room( this_object(),output);

	money *= win==1?2:9;
	silver = new(SILVER_OB);
	silver->set_amount(money);

	if(!silver->move(better))
	{
		destruct(silver);
		better->add("save_in_bank/silver",money);
		tell_object(better,"���ò��˸���Ķ����ˣ���Ӯ��Ǯ�Ѿ��浽��������˻����ˡ�\n");
	}

	imp = money/5;
	if(imp < 1)
		imp = 1;

	better->improve_skill("betting",imp);

}
