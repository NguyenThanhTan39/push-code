extends Node

var score = 0

@onready var score_labels: Label = $ScoreLabels

func add_point() -> void:
	score += 1
	score_labels.text = "You collected " + str(score) + " coins."
