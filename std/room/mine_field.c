/************************************************
 * mine_field.c                                 *
 *                                              *
 * ��                                         *
 ************************************************/

/*
1���Ƿ��г���
2�����߳�
3����������
4�����̲���
5�����ɼ���
6����ʯ����Ч����ĺ�������
7��������
8����ʯ���
9�����۷���
10���ǿ��۷���
�Ժ����������ɾ���󳤵Ŀ���Ȩ
*/

#pragma optimize

#define N		8
#define S		4
#define W		2
#define E		1
#define ALL		15

#define MAX_LONG	40
#define MIN_CONTAIN_PERSENT	5
#define MAX_CONTAIN_PERSENT	30

#define TWO_VALID_LEAVES

#include <mine_def.h>

inherit F_SAVE;
inherit F_NATURE;

class coordinate{ int x; int y; }

protected nosave class coordinate *newpath = ({});	// ���������
	
protected nosave string *valid_dirs = ({ "south","north","west","east" });
protected nosave mapping reverse_dir = ([
"north" : "south",
"south" : "north",
"west"  : "east",
"east"  : "west",
]);

// һЩ�ɴ���ı���
protected int maze_built = 0;	// �������
protected mixed *all;		// ȫ�Թ���������.
protected class coordinate enter;	// �������
protected class coordinate leave;	// ��������
protected class coordinate *mine_room_positions;	// ���۷ֲ�
protected int out_mine;		// �ѿ��ɵ���
protected int built_time;	// ���һ�εĸ���ʱ��

/***************** �󳡵�һЩԤ�����ԣ�*****************/
protected nosave int l;				// ���߳�
protected nosave string entry_dir;		// ��ڷ���
protected nosave string link_entry_dir;		// �������������ӷ���
protected nosave string link_entry_room;	// ������������򵵰����ļ���
protected nosave string link_exit_dir;		// ��������������ӷ���
protected nosave string link_exit_room;		// �������������򵵰����ļ���
protected nosave string mine_room;		// �п󷿼�
protected nosave string no_mine_room;		// �޿󷿼�
protected nosave string mine_class;		// �������
protected nosave int contain_persent;		// ��ʯ����Ч����ĺ�������
protected nosave int contain_quantity;		// ��ʼ���̲���
protected nosave int reset_time_sect;		// �������ڣ���λ��Game�꣩
/******************* ---- END ---- *********************/

// ����ȫ�����.
protected void refresh_vars();

// �����󳡵�ͼ
protected void create_maze();

// ѡ���������.
protected int random_out(int x,int y,int n);

// ��������.
protected void link_to_north(int x,int y);
protected void link_to_south(int x,int y);
protected void link_to_west(int x,int y);
protected void link_to_east(int x,int y);

protected string mroom_fname(int x,int y)
{ return sprintf("%s/%d/%d",base_name(this_object()),x,y);}

string query_save_file() { return base_name(this_object()); }

protected void refresh_vars() // ����ȫ�����.
{
	newpath = ({});
	all = 0;
	maze_built = 0;
}

// ��һЩ��������ĺϷ��Լ��
protected int check_vars()
{
	if( (l < 10) || (l > MAX_LONG) )
		return 0;

	if(!stringp(link_entry_room)
	|| !sizeof(link_entry_room)
	|| (file_size(link_entry_room + ".c") <= 0) )
		return 0;

	if(!stringp(mine_room)
	|| !sizeof(mine_room)
	|| (file_size(mine_room + ".c") <= 0) )
		return 0;

	if(!stringp(no_mine_room)
	|| !sizeof(no_mine_room)
	|| (file_size(no_mine_room + ".c") <= 0) )
		return 0;

/*
	if(!stringp(mine_stone)
	|| !sizeof(mine_stone)
	|| (file_size(mine_stone + ".c") <= 0) )
		return 0;
*/
	if(!intp(contain_quantity) || (contain_quantity <= 0))
		return 0;

	if(!intp(contain_persent) || (contain_persent <= 0))
		return 0;

	return 1;
}

protected int random_out(int x,int y,int n) // ѡ��������ں���.
{
	int *outs = ({}), retn = 0;
	class coordinate temp;

	// The west room is (x-1,y)
	if( n&W
	&& ((x-1) >= 0)
	&& !all[x-1][y] )
	{
		temp = new(class coordinate);
		temp->x = x-1;
		temp->y = y;
		outs += ({ W });
	}

	// The east room is (x+1,y)
	if( n&E
	&& ((x+1) < l)
	&& !all[x+1][y] )
	{
		temp = new(class coordinate);
		temp->x = x+1;
		temp->y = y;
		outs += ({ E });
	}

	// The south room is (x,y-1)
	if( n&S
	&& ((y-1) >= 0)
	&& !all[x][y-1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y-1;
		outs += ({ S });
	}

	// The north room is (x,y+1)
	if( n&N
	&& ((y+1) < l)
	&& !all[x][y+1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y+1;
		outs += ({ N });
	}

#ifdef TWO_VALID_LEAVES
	// �������������,����ر�һ��.
	if(sizeof(outs) >= 3)
		outs -= ({ outs[random(sizeof(outs))] });
#endif

	for(int i=0;i<sizeof(outs);i++)
		retn |= outs[i];

	return retn;
}


// ���۷ֲ��ܶȼ��
protected int valid_mine_position(int x, int y)
{
	int n;

	if(!all[x][y])	// û����
		return 0;

	if(!n = sizeof(mine_room_positions))
		return 1;

	for(int i=0; i<n; i++)
	{
		//if( abs( (mine_room_positions[i]->x - x) * (mine_room_positions[i]->y - y) ) < 40)
		if((mine_room_positions[i]->x == x) && (mine_room_positions[i]->y == y))
			return 0;
	}

	return 1;
}

// �������۷ֲ�����
protected void create_mine_room()
{
	int num, x, y;

	num = l*l/30;

	if(num < 1)
		num = 1;

	do
	{
		class coordinate tmp;

		x = random(l-3) + 1;
		y = random(l-3) + 1;

		if(!valid_mine_position(x,y))
			continue;
		tmp = new(class coordinate);
		tmp->x = x;
		tmp->y = y;

		if(!mine_room_positions || !sizeof(mine_room_positions))
			mine_room_positions = ({ tmp });
		else
			mine_room_positions += ({ tmp });
	}
	while(sizeof(mine_room_positions) < num);
}

protected void create_maze()
{
	int i;
	class coordinate *valid_leaves=({}),temp;

	refresh_vars(); // ����ȫ�����.
	if( !check_vars() )   // ��һЩԤ��������м�顣
		return;

	// ���߳�.
	all = allocate(l);
	for(i=0;i<l;i++)
		all[i] = allocate(l);	// ��������.

	enter = new(class coordinate);

	switch (entry_dir)
	{
		case "south":
			// enter �������.
			enter->x = to_int(l/2); // ȡ���Թ��Ƚ�ƽ�⡣
			enter->y = 0;
			all[enter->x][enter->y] |= S;
			break;
		case "north":
			enter->x = to_int(l/2);
			enter->y = l-1;
			all[enter->x][enter->y] |= N;
			break;
		case "west":
			enter->y = to_int(l/2);
			enter->x = 0;
			all[enter->x][enter->y] |= W;
			break;
		case "east":
			enter->y = to_int(l/2);
			enter->x = l-1;
			all[enter->x][enter->y] |= E;
			break;
	}

	// ������������.
	newpath += ({ enter });

	// ������ѭ��.
	do
	{
		int x,y,out,numb;

		// ����һЩ������ʼ��.
		if( !(numb=sizeof(newpath)) )
			continue;
		numb = random(numb);
		reset_eval_cost();
		x = newpath[numb]->x;
		y = newpath[numb]->y;

		// ������������ܵĳ�������ر�һ������:
		out = ALL^(all[x][y]);
		out = random_out(x,y,out);

		if(!out) // û�п��ܵĳ�����.
		{
			newpath -= ({ newpath[numb] });
			continue;
		}

		// ��������.
		if(out&W) link_to_west(x,y);
		if(out&E) link_to_east(x,y);
		if(out&N) link_to_north(x,y);
		if(out&S) link_to_south(x,y);

		// ��ǰ���䴦�����.
		newpath -= ({ newpath[numb] });
	}
	while (sizeof(newpath));

	switch (entry_dir)
	{
		case "west":
			for(i=0;i<l;i++)
				if(all[l-1][i])
				{
					temp = new(class coordinate);
					temp->x = l-1;
					temp->y = i;
					valid_leaves += ({temp});
				}
			break;
		case "east":
			for(i=0;i<l;i++)
				if(all[0][i])
				{
					temp = new(class coordinate);
					temp->x = 0;
					temp->y = i;
					valid_leaves += ({temp});
				}
			break;
		case "south":
			for(i=0;i<l;i++)
				if(all[i][l-1])
				{
					temp = new(class coordinate);
					temp->x = i;
					temp->y = l-1;
					valid_leaves += ({temp});
				}
			break;
		case "north":
			for(i=0;i<l;i++)
				if(all[i][0])
				{
					temp = new(class coordinate);
					temp->x = i;
					temp->y = 0;
					valid_leaves += ({temp});
				}
			break;
	}

	if( !(i=sizeof(valid_leaves)) ) // δ����Է��߽�
	{
		call_other(this_object(),"create_maze");
		return;
	}


	if(stringp(link_exit_room)
	&& sizeof(link_exit_room)
	&& (file_size(link_exit_room + ".c") > 0) )
	{
		if(i == 1)
			leave = valid_leaves[0];
		else
			leave = valid_leaves[random(i)]; // ���ѡһ��.

		switch (entry_dir)
		{
			case "south":
				all[leave->x][leave->y] |= N;
				break;
			case "north":
				all[leave->x][leave->y] |= S;
				break;
			case "west":
				all[leave->x][leave->y] |= E;
				break;
			case "east":
				all[leave->x][leave->y] |= W;
				break;
		}
	}

	create_mine_room();

	maze_built = 1;
	built_time = query_year()*12 + query_month();
	save();
}

protected void link_to_west(int x,int y)	// The west room is (x-1,y)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ���������ķ�����.
	if( (x-1) < 0 )
		return;

	temp = new(class coordinate);
	temp->x = x-1;
	temp->y = y;

	// ����ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= W;
	all[temp->x][temp->y] |= E;
	newpath += ({temp});
}

protected void link_to_east(int x,int y)	// The east room is (x+1,y)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ������ķ�����.
	if( (x+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x+1;
	temp->y = y;

	// ����ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= E;
	all[temp->x][temp->y] |= W;
	newpath += ({temp});
}

protected void link_to_south(int x,int y)	// The south room is (x,y-1)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ������϶˵ķ�����.
	if( (y-1) <0 )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y-1;

	// �϶˵ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= S;
	all[temp->x][temp->y] |= N;
	newpath += ({temp});
}

protected void link_to_north(int x,int y)	// The north room is (x,y+1)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ�����˵ķ�����.
	if( (y+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y+1;

	// ���˵ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y] |= N;
	all[temp->x][temp->y] |= S;
	newpath += ({temp});
}

void remove(string euid)
{
	string fname = base_name(this_object());
	object m_room;
	int x,y;

	for(x=0;x<l;x++)
		for(y=0;y<l;y++)
			if(objectp(m_room = find_object(sprintf("%s/%d/%d",fname,x,y))))
				destruct(m_room);
	if(m_room = find_object(sprintf("%s/entry",fname)))
		destruct(m_room);
	if(m_room = find_object(sprintf("%s/exit",fname)))
		destruct(m_room);
}

/**** ������Ԥ������Ľӿں��� ****/
// ���߳�
void set_maze_long(int mlong)
{
	if(!intp(mlong))
		return;

	// ��СΪ 10
	if( (mlong < 10) || (mlong > MAX_LONG) )
		return;

	l = mlong;
}

// ���۷����ļ���
void set_mine_room(string room_files)
{
	object ob;

	if(!stringp(room_files) || !sizeof(room_files))
		error("set_mine_room: ��������Ϊ string ����\n");

	if(file_size(sprintf("%s.c",room_files)) <= 0)
		error("set_mine_room: ����ָ���ķ����ļ������ڣ�������Ȩ��ȡ\n");

	if( !objectp(ob = find_object(room_files)) )
		ob = load_object(room_files);
	if(!objectp(ob))
		error("set_mine_room: ����ָ���ķ����޷�����\n");
	mine_room = room_files;
}

// �ǿ��۷����ļ���
void set_no_mine_room(string room_files)
{
	object ob;

	if(!stringp(room_files) || !sizeof(room_files))
		error("set_no_mine_room: ��������Ϊ string ����\n");

		// �����Ƿ����
	if(file_size(sprintf("%s.c",room_files)) <= 0)
		error("set_no_mine_room: ����ָ���ķ����ļ������ڣ�������Ȩ��ȡ\n");

	if( !objectp(ob = find_object(room_files)) )
		ob = load_object(room_files);
	if(!objectp(ob))
		error("set_no_mine_room: ����ָ���ķ����޷�����\n");
	no_mine_room = room_files;
}

// �趨��ʼ���̲���
void set_contain_quantity(int num)
{
	if(!intp(num) || (num <= 0))
		error("set_contain_quantity: �趨��������\n");
	contain_quantity = num;
}

// �趨�̲ر���
void set_contain_persent(int num)
{
	if(!intp(num)
	|| (num < MIN_CONTAIN_PERSENT)
	|| (num > MAX_CONTAIN_PERSENT) )
		error("set_contain_persent: �����趨����\n");

	contain_persent = num;
}

// �趨���������
void set_reset_time_sect(int num)
{
	if(!intp(num) || (num <= 0))
		error("set_reset_time_sect: �����趨����\n");

	reset_time_sect = num;
}

void set_mine_class(string mclass)
{
	if(!stringp(mclass) || !sizeof(mclass))
		error("set_mine_class: �����趨����\n");
	mine_class = mclass;
}

// ��ڷ���(�����ڶ���)
void set_entry_dir(string dir)
{
	if(!stringp(dir))
		return;

	// ��ڷ���ĺϷ��Լ��.
	if(member_array(dir,valid_dirs) == -1)
		return;

	entry_dir = dir;
}

//�������������ӷ���
void set_link_entry_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_entry_dir = dir;
}

// ������������򵵰����ļ���
void set_link_entry_room(string room_files)
{
	object ob;

	if(!stringp(room_files) || !sizeof(room_files))
		error("set_link_entry_room: ��������Ϊ string ����\n");

		// �����Ƿ����
	if(file_size(sprintf("%s.c",room_files)) <= 0)
		error("set_link_entry_room: ����ָ���ķ����ļ������ڣ�������Ȩ��ȡ\n");

	if( !objectp(ob = find_object(room_files)) )
		ob = load_object(room_files);
	if(!objectp(ob))
		error("set_link_entry_room: ����ָ���ķ����޷�����\n");
	link_entry_room = room_files;
}

//��������������ӷ���
void set_link_exit_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_exit_dir = dir;
}

// �Թ��������������򵵰����ļ���
void set_link_exit_room(string room_files)
{
	object ob;

	if(!stringp(room_files) || !sizeof(room_files))
		error("set_link_exit_room: ��������Ϊ string ����\n");

		// �����Ƿ����
	if(file_size(sprintf("%s.c",room_files)) <= 0)
		error("set_link_exit_room: ����ָ���ķ����ļ������ڣ�������Ȩ��ȡ\n");

	if( !objectp(ob = find_object(room_files)) )
		ob = load_object(room_files);
	if(!objectp(ob))
		error("set_link_exit_room: ����ָ���ķ����޷�����\n");

	link_exit_room = room_files;
}
/**** ������Ԥ������Ľӿں��� ****/

// �� VIRTUAL_D ���ô��췿�䡣
nomask object query_maze_room(string str)
{
	int idx,x,y,exits, n;
	object ob;

	if( previous_object() && (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if(!stringp(str) || str == "")
		return 0;

	if(!maze_built)
	{
		restore();
		if(!maze_built)
			create_maze();
	}

	if(!maze_built)
		return 0;

	if(str == "entry")	// ���Ϊ�ǿ��۷���
	{
		ob = new(no_mine_room);
		if(!ob)
			return 0;
		ob->set(sprintf("exits/%s",link_entry_dir),link_entry_room);
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),mroom_fname(enter->x,enter->y));
		return ob;
	}

	if(str == "exit")	// ����Ϊ�ǿ��۷���
	{
		if(!leave || !link_exit_room || !sizeof(link_exit_room))
			return 0;

		ob = new(no_mine_room);
		if(!ob)
			return 0;
		ob->set(sprintf("exits/%s",link_exit_dir),link_exit_room);
		ob->set(sprintf("exits/%s",entry_dir),
			mroom_fname(leave->x,leave->y));
		return ob;
	}

	idx = member_array('/', str);
	if( idx == -1 )
		return 0;

	if(!sscanf(str[0..idx-1],"%d",x))
		return 0;
	if(!sscanf(str[idx+1..],"%d",y))
		return 0;

	if( !exits = all[x][y] )
		return 0;

	n = sizeof(mine_room_positions);
	for(int i=0;i<n;i++)
	{
		if( (x == mine_room_positions[i]->x)
		&& (y == mine_room_positions[i]->y) )
		{
			ob = new(mine_room);
			break;
		}
	}

	if(!ob)
		ob = new(no_mine_room);
	if(!ob)
		return 0;

	if(exits&W)
		ob->set("exits/west",mroom_fname(x-1,y));
	if(exits&E)
		ob->set("exits/east",mroom_fname(x+1,y));
	if(exits&N)
		ob->set("exits/north",mroom_fname(x,y+1));
	if(exits&S)
		ob->set("exits/south",mroom_fname(x,y-1));

	if( (x == enter->x) && (y == enter->y) )
		ob->set(sprintf("exits/%s",entry_dir),
			sprintf("%s/entry",base_name(this_object())));


	if( classp(leave) && (x == leave->x) && (y == leave->y) )
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),
			sprintf("%s/exit",base_name(this_object())));

	return ob;
}

void setup_stone(object stone)
{
	int w;

	if(!maze_built
	|| !stone
	|| !stone->is_mine_stone()
	|| (out_mine >= contain_quantity) )
		return;

	if(!w = stone->query_weight()/100*contain_persent/100)
		return;

	stone->set_mine_class(mine_class);

	w = w*7/10 + random(w*3/10);
	if(w < 1)
		w = 1;

	out_mine += w;	// ��¼�ѿ�����

	stone->set_eff_weight(w);
}


protected void reset_mine_field()
{
	out_mine = 0;
	save();
}

void reset()
{
	int tm;

	if(!maze_built)
		return;

	save();

	if(built_time <= 0)
	{
		built_time = query_year()*12 + query_month();
		return;
	}
	tm = query_year()*12 + query_month();

	if((tm - built_time) > (reset_time_sect*12))
		reset_mine_field();
}
