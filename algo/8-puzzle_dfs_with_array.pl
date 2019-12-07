#!/usr/env/bin perl

use feature qw/ say /;
use constant FALSE => 0;
use constant TRUE => 1;
use Data::Dumper;

my $map = [ [2, 8, 3], [1, 6, 4], [7, 0, 5] ];
my $goal = [ [1, 2, 3], [8, 0, 4], [7, 6, 5] ];
my $count = 0;

my $cached_map = [];

my @my = (-1, 1, 0, 0);
my @mx = (0, 0, -1, 1);

trans_with_dfs($map, $goal, \$count);

sub trans_with_dfs {
    my ($map, $goal, $count) = @_;
    say $$count if dfs($map, $goal, 2, 1, $count);
}

sub dfs {
    my ($map, $goal, $y, $x, $count) = @_;
    $$count++;
    say $$count;
    return FALSE if is_cached($map);
    add_map_to_cache($map);
    return TRUE if are_same_map($map, $goal);
    for my $i (0..3) {
        my $ny = $y + $my[$i];
        my $nx = $x + $mx[$i];
        next if !is_valid_coord($ny, $nx);
        my $transformed_map = trans_map($map, $y, $x, $ny, $nx);
        return TRUE if dfs($transformed_map, $goal, $ny, $nx, $count);
    }
    return FALSE;
}

sub trans_map {
    my ($map, $y, $x, $ny, $nx) = @_;
    my $transformed_map = [];
    for my $y (0..$#$map) {
        for my $x (0..$#{$map->[$y]}){
            $transformed_map->[$y][$x] = $map->[$y][$x];
        }
    }
    my $tmp = $transformed_map->[$y][$x];
    $transformed_map->[$y][$x] = $transformed_map->[$ny][$nx];
    $transformed_map->[$ny][$nx] = $tmp;
    return $transformed_map;
}

sub is_cached {
    my $map = shift;
    my $l1 = $map->[0][0];
    my $l2 = $map->[0][1];
    my $l3 = $map->[0][2];
    my $l4 = $map->[1][0];
    my $l5 = $map->[1][1];
    my $l6 = $map->[1][2];
    my $l7 = $map->[2][0];
    my $l8 = $map->[2][1];
    my $l9 = $map->[2][2];
    if ( defined $cached_map->[$l1][$l2][$l3][$l4][$l5][$l6][$l7][$l8][$l9] ) {
        return $cached_map->[$l1][$l2][$l3][$l4][$l5][$l6][$l7][$l8][$l9] == 1;
    }
    else {
        return undef;
    }
}

sub add_map_to_cache {
    my $map = shift;
    my $l1 = $map->[0][0];
    my $l2 = $map->[0][1];
    my $l3 = $map->[0][2];
    my $l4 = $map->[1][0];
    my $l5 = $map->[1][1];
    my $l6 = $map->[1][2];
    my $l7 = $map->[2][0];
    my $l8 = $map->[2][1];
    my $l9 = $map->[2][2];
    $cached_map->[$l1][$l2][$l3][$l4][$l5][$l6][$l7][$l8][$l9] = 1;
}

sub map_to_number {
    my $map = shift;
    my $number = 0;
    my $e = 8;
    for my $row (@$map) {
        for my $col (@$row) {
            $number += $col * 10**$e;
            $e--;
        }
    }
    return $number;
}

sub are_same_map {
    my ($map1, $map2) = @_;
    my $num1 = map_to_number($map1);
    my $num2 = map_to_number($map2);
    return $num1 == $num2;
}

sub is_valid_coord {
    my ($y, $x) = @_;
    return ($y >= 0 and $y < 3 and $x >= 0 and $x < 3);
}


sub min {
    my @numbers = @_;
    my $min = shift @numbers;
    for ( @numbers ) {
        $min = $min<$_ ? $min : $_;
    }
    return $min;
}

sub max {
    my @numbers = @_;
    my $max = shift @numbers;
    for ( @numbers ) {
        $max = $max > $_ ? $max : $_;
    }
    return $max;
}
